#pragma once

#include <memory>

#include <QWidget>

#include "potterExport.h"

namespace POTTER
{
class POTTER_EXPORT PotterWidget : public QWidget
{
public:
    PotterWidget();

    void LoadDocument(const QString& fileName);

private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};
} // POTTER