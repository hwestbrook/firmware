BOOST_VERSION=1_59_0

# this was previously hardcoded to 1.59.0 in the path, replacing with a fast source
#test -f boost_$BOOST_VERSION.tar.gz || wget --quiet http://downloads.sourceforge.net/project/boost/boost/1.59.0/boost_$BOOST_VERSION.tar.gz
export BOOST_ROOT=$HOME/.ci/boost/boost_$BOOST_VERSION
export BOOST_LIBRARYDIR=$BOOST_ROOT/stage/lib
mkdir -p $BOOST_ROOT
test -d $BOOST_ROOT || ( echo "boost root $BOOST_ROOT not created." && exit 1)
test -f $BOOST_ROOT/INSTALL || wget --quiet https://s3.amazonaws.com/spark-assets/boost_${BOOST_VERSION}.tar.gz -O - | tar -xz -C $BOOST_ROOT --strip-components 1
export DYLD_LIBRARY_PATH="${BOOST_LIBRARYDIR}:$DYLD_LIBRARY_PATH"
export LD_LIBRARY_PATH="${BOOST_LIBRARYDIR}:$LD_LIBRARY_PATH"
