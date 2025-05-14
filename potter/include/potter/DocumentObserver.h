#pragma once
#include <QVector>

#include "potterExport.h"

namespace POTTER
{
class Page;

class POTTER_EXPORT DocumentObserver
{
public:
    enum SetupFlags
    {
        DocumentChanged = 1, ///< The document is a new document.
    };

    DocumentObserver();
    /**
     * Destroys the document observer.
     */
    virtual ~DocumentObserver();

    DocumentObserver(const DocumentObserver&) = delete;
    DocumentObserver& operator=(const DocumentObserver&) = delete;

    virtual void notifySetup(const QVector<Page*>& pages, int setupFlags);

    virtual void NotifyZoom(int factor);

    virtual void NotifyViewportChanged(bool smoothMove);

    virtual void NotifyCurrentPageChanged(int previous, int current);
};
} // POTTER