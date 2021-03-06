# qMakeTorrent
* Current version: 1.1.2
* Author: kz26
* License: BSD 2-clause

## **qMakeTorrent is no longer actively developed. Please consider using [dottorrent-gui](https://github.com/kz26/dottorrent-gui) instead.**


## Description
qMakeTorrent is an advanced torrent creator with batch capability.

## Installation
### Windows
[Click here](https://github.com/kz26/qMakeTorrent/releases) to download ready-to-use binaries.

You may need to download the [Visual C++ Redistributable Packages for Visual Studio 2013](http://www.microsoft.com/en-us/download/details.aspx?id=40784).

### Linux/UNIX
Download the source for a [stable release version](https://github.com/kz26/qMakeTorrent/tags) or clone the latest development source from GitHub.
Building qMakeTorrent requires a Qt4 development environment, C++/Boost 1.46+, and a recent version of libtorrent (>= 0.15.x).

    $ qmake
    $ make

### Mac OS X
In theory compilation should be the same as on Linux/UNIX. I do not have access to a Mac system at this time, but if someone wishes to contribute binaries
I will be more than happy to post them.


## Usage
1. Click "Add File" or "Add Directory" to select an input file or directory. If a directory is
selected, the option to use batch mode will be enabled. In batch mode, qMakeTorrent creates a torrent
for each subdirectory and file directly below the input path.
2. Next, you will be asked to choose an output path for your torrent(s). If your input was a single file
or directory, you will be asked to choose the save location of the .torrent file. If your input was a directory
with batch mode enabled, you will be asked to choose a directory in which to save the .torrent files. In this case,
each torrent will be named <subdirectory name>.torrent.
3. On the next page, set the comment, piece size, and private flag as desired.
4. Wait for your torrents to be created.

## Support
Please use the GitHub Issue Tracker and pull request system to report bugs/issues and submit improvements/changes, respectively.


