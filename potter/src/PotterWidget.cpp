#include "potter/PotterWidget.h"
#include "potter/Provider.h"

namespace POTTER
{
struct PotterWidget::Impl
{
    std::unique_ptr<Provider> provider;
};

PotterWidget::PotterWidget() : pImpl(std::make_unique<Impl>())
{
}

void PotterWidget::LoadDocument(const QString& fileName)
{
    
}
} // POTTER