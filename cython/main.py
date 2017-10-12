import write_features_file_cython as wffc
import numpy as np

if __name__ == '__main__':
    print(wffc.values2str(np.arange(10, dtype=np.float)))
