/*
    pqConsole    : interfacing SWI-Prolog and Qt

    Author       : Carlo Capelli
    E-mail       : cc.carlo.cap@gmail.com
    Copyright (C): 2013, Carlo Capelli

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <QApplication>

#if 0

#include "pqConsole.h"

// run a console window instanced from shared library
int main(int argc, char *argv[]) {
    return pqConsole().runDemo(argc, argv);
}

#elif 0

#include "mainwindow.h"

// instance a local console window, running SWI-Prolog UI
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w(argc, argv);
    w.show();
    return a.exec();
}

#elif 1

#include <QMetaType>
#include <QMetaObject>
#include "PREDICATE.h"
#include "pqConsole.h"

// collect all meta-instantiable Qt types
//
PREDICATE(listq, 1) {
    PlTail l(A1);
    for (int t = 0; t < (1 << 20); ++t)
        if (QMetaType::isRegistered(t)) {
            const char* n = QMetaType::typeName(t);
            if (n && *n)
                l.append(n);
        }
    l.close();
    return TRUE;
}

// create a meta-instantiable Qt object
//
PREDICATE(newq, 2) {
    int id = QMetaType::type(A1);
    if (id != 0) {
        //A2 = QMetaType::construct(id);
        return TRUE;
    }
    return FALSE;
}

// run GUI from shared library, extended with locally defined builtins
//
int main(int argc, char *argv[]) {
    return pqConsole().runDemo(argc, argv);
}

#endif
