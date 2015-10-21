from __future__ import print_function

import numpy as np
from netCDF4 import Dataset

ncout = Dataset('out.nc','w')
ncout.createDimension('time',None)

nctime = ncout.createVariable('time',np.float64,('time',))
nctime.units = 'seconds since '+\
               '1999-01-01 00:00:00'
nctime[:] = np.arange(0,10,1)

ncout.close()
