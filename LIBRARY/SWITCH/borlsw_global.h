#ifndef BORLSW_GLOBAL_H
#define BORLSW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BORLSW_LIBRARY)
#  define BORLSWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BORLSWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BORLSW_GLOBAL_H
