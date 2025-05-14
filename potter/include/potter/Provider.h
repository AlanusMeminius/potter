#pragma once

#include <QObject>
#include <QVariantList>

#include "potter/Page.h"
#include "potterExport.h"

namespace POTTER
{
class POTTER_EXPORT Provider : public QObject
{
    Q_OBJECT

public:
    explicit Provider(QObject* parent = nullptr, const QVariantList& args = QVariantList());

    ~Provider() override;

    virtual bool LoadDocument(const QString& fileName, QVector<Page*>& pages);

    bool CloseDocument();
};
} // POTTER