#ifndef CONSOLEUI_GLOBAL_H
#define CONSOLEUI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CONSOLEUI_LIBRARY)
#  define CONSOLEUI_EXPORT Q_DECL_EXPORT
#else
#  define CONSOLEUI_EXPORT Q_DECL_IMPORT
#endif

#endif // CONSOLEUI_GLOBAL_H
