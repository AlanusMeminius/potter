#pragma once

#include <QtTypes>

#include "potterExport.h"

namespace POTTER
{
class POTTER_EXPORT Page
{
    Page(uint pageNumber, double width, double height);
    ~Page();

    /**
    * Returns the width of the page.
    */
    [[nodiscard]] double width() const;

    /**
     * Returns the height of the page.
     */
    [[nodiscard]] double height() const;
};
} // POTTER