# Implementation of eRPC for GRBLHAL IOStreams.

#
# Generated by erpcgen 1.9.0 on Sun Jun  5 12:51:54 2022.
#
# AUTOGENERATED - DO NOT EDIT
#

try:
    from erpc import erpc_version
    version = erpc_version.ERPC_VERSION
except ImportError:
    version = "unknown"
if version != "1.9.0":
    raise ValueError("The generated shim code version (1.9.0) is different to the rest of eRPC code (%s). \
Install newer version by running \"python setup.py install\" in folder erpc/erpc_python/." % repr(version))

from . import common
from . import client
from . import server
from . import interface
