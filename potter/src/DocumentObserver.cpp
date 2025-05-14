#include "potter/DocumentObserver.h"

namespace POTTER
{
    DocumentObserver::DocumentObserver()
    {
    }

    DocumentObserver::~DocumentObserver()
    {
    }

    void DocumentObserver::notifySetup(const QVector<Page*>& pages, int setupFlags)
    {
    }

    void DocumentObserver::NotifyZoom(int factor)
    {
    }

    void DocumentObserver::NotifyViewportChanged(bool smoothMove)
    {
    }

    void DocumentObserver::NotifyCurrentPageChanged(int previous, int current)
    {
    }
} // POTTER
