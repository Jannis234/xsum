# This file is part of xsum
#
# xsum is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# xsum is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with xsum. If not, see <http://www.gnu.org/licenses/>.

echo "// Auto-generated, edit config_build.mak instead"
echo
echo "#ifndef __XSUM_CONFIG_GENERATED_H__"
echo "#define __XSUM_CONFIG_GENERATED_H__"
echo
echo "#define XSUM_VERSION_STRING \"$1\""
echo
echo "#define XSUM_CONFIG_NETTLE $2"
echo "#define XSUM_CONFIG_LIBGCRYPT $3"
echo
echo "#endif"
