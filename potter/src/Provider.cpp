#include "potter/Provider.h"

namespace POTTER
{
Provider::Provider(QObject* parent, const QVariantList& args)
{
}

Provider::~Provider()
= default;

bool Provider::LoadDocument(const QString& fileName, QVector<Page*>& pagesVector)
{
    return false;
}

bool Provider::CloseDocument()
{
    return false;
}
} // POTTER