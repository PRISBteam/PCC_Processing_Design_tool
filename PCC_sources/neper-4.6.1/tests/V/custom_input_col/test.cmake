# This file is part of the Neper software package.
# Copyright(C) 2003-2022, Romain Quey.
# See the COPYING file in the top-level directory.

set (test_command -V "file(pts)" -datapointcol id -imageformat pov -print test)
include(../../test.cmake)