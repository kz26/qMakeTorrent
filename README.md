# qMakeTorrent
* Current version: 1.0.2
* Author: whitehat2k9
* License: BSD
* [Website](http://whitehat2k9.github.com/qMakeTorrent)
* [Source repository](http://github.com/whitehat2k9/qMakeTorrent)

## Description
qMakeTorrent is an advanced torrent creator with batch capability.

## Installation
### Windows
[Click here](http://whitehat2k9.github.com/qMakeTorrent/bin/qMakeTorrent-1.0.2-win32.zip) to download
a prebuilt version for Windows.

You may need to download the [Microsoft Visual C++ 2010 SP1 Redistributable Package (x86)](http://www.microsoft.com/en-us/download/details.aspx?id=8328).

### Linux/UNIX
Download a [stable release version](https://github.com/whitehat2k9/qMakeTorrent/tags) or clone the latest development source from GitHub.
Building qMakeTorrent requires a Qt4 development environment, C++/Boost 1.46+, and a recent version of libtorrent (>= 0.15.x).

    $ qmake
    $ make

### Mac
In theory compilation should be the same as on Linux/UNIX. If someone wishes to contribute binaries
I will be more than happy to post them.


## Usage
1. Click "Add File" or "Add Directory" to select an input file or directory. If a directory is
selected, the option to use batch mode will be enabled. In batch mode, qMakeTorrent creates a torrent
for each subdirectory directly below the input path.
2. Next, you will be asked to choose an output path for your torrent(s). If your input was a single file
or directory, you will be asked to choose the save location of the .torrent file. If your input was a directory
with batch mode enabled, you will be asked to choose a directory in which to save the .torrent files. In this case,
each torrent will be named <subdirectory name>.torrent.
3. On the next page, set the creator, comment, piece size, and private flag as desired.
4. Wait for your torrents to be created.

## Support
Please use the GitHub Issue Tracker and pull request system to report bugs/issues and submit improvements/changes, respectively.


