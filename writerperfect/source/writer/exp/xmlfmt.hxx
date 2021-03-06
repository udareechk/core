/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_WRITERPERFECT_SOURCE_WRITER_EXP_XMLFMT_HXX
#define INCLUDED_WRITERPERFECT_SOURCE_WRITER_EXP_XMLFMT_HXX

#include <map>

#include <librevenge/librevenge.h>

#include "xmlictxt.hxx"

namespace writerperfect
{
namespace exp
{

/// Handler for <office:automatic-styles>/<office:styles>.
class XMLStylesContext : public XMLImportContext
{
public:
    XMLStylesContext(XMLImport &rImport, std::map<OUString, librevenge::RVNGPropertyList> &rParagraphStyles, std::map<OUString, librevenge::RVNGPropertyList> &rTextStyles);

    rtl::Reference<XMLImportContext> CreateChildContext(const OUString &rName, const css::uno::Reference<css::xml::sax::XAttributeList> &xAttribs) override;

    std::map<OUString, librevenge::RVNGPropertyList> &GetCurrentParagraphStyles();
    std::map<OUString, librevenge::RVNGPropertyList> &GetCurrentTextStyles();
private:
    std::map<OUString, librevenge::RVNGPropertyList> &m_rParagraphStyles;
    std::map<OUString, librevenge::RVNGPropertyList> &m_rTextStyles;
};

} // namespace exp
} // namespace writerperfect

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
