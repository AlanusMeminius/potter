#pragma once

#include "potterExport.h"
#include "Provider.h"

namespace POTTER
{
class POTTER_EXPORT MuPDFProvider : public Provider
{
public:
    MuPDFProvider();
    ~MuPDFProvider() override;

    bool LoadDocument(const QString& fileName, QVector<Page*>& pages) override;

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl; 
};
} // POTTER