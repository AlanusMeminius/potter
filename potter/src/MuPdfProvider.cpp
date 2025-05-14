#include "potter/MuPdfProvider.h"
#include <mupdf/fitz.h>

namespace POTTER
{
struct MuPDFProvider::Impl
{
    fz_document* mDoc{nullptr};
    fz_context* mContext{nullptr};

    Impl()
    {
        mContext = fz_new_context(nullptr, nullptr, FZ_STORE_UNLIMITED);
        fz_register_document_handlers(mContext);
    }

    ~Impl()
    {
        fz_drop_document(mContext, mDoc);
        fz_drop_context(mContext);
    }

    void GenerateIndex()
    {
        // mIndex = { "", 0, "", FileIndexType::FILE };

        fz_outline* top_toc{nullptr};
        fz_try(mContext)
            top_toc = fz_load_outline(mContext, mDoc);
        fz_catch(mContext)
        {
            // qCritical () << "load " << mFilename << " outline error";
            fz_report_error(mContext);
            top_toc = nullptr;
        }

        if (top_toc == nullptr)
            return;

        auto toc = top_toc;
        while (toc != nullptr)
        {
            // auto child_index = FileIndex{};
            // generateIndexRecursively (child_index, toc);
            // mIndex.mChildrenIndex.push_back (child_index);
            toc = toc->next;
        }

        fz_drop_outline(mContext, top_toc);
    }
};

MuPDFProvider::MuPDFProvider()
    : pImpl(std::make_unique<Impl>())
{
}

MuPDFProvider::~MuPDFProvider()
= default;

bool MuPDFProvider::LoadDocument(const QString& fileName, QVector<Page*>& pages)
{
    pImpl->mDoc = fz_open_document(pImpl->mContext, fileName.toUtf8().constData());
    if (pImpl->mDoc == nullptr)
    {
        return false;
    }

    // generateIndex();
    return true;
    // return Provider::LoadDocument(fileName, pages);
}
} // POTTER