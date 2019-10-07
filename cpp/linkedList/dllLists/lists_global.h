#ifndef LISTS_GLOBAL_H
#define LISTS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LISTS_LIBRARY)
#  define LISTSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LISTSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LISTS_GLOBAL_H
