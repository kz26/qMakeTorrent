/* * qMakeTorrent - Advanced torrent creator with batch capability
 * Copyright (C) 2013 whitehat2k9 <whitehat2k9@gmail.com>
 *
 * This file is part of qMakeTorrent.
 *
 * qMakeTorrent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * qMakeTorrent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qMakeTorrent.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INTROPAGE_H
#define INTROPAGE_H

#include <QWizardPage>

namespace Ui {
class IntroPage;
}

class IntroPage : public QWizardPage
{
    Q_OBJECT
    
public:
    explicit IntroPage(QWidget *parent = 0);
    ~IntroPage();
    
private:
    Ui::IntroPage *ui;
};

#endif // INTROPAGE_H
