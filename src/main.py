import sys
from struct import calcsize,unpack

class IFile:
    def __init__(self, **kwds):
        self.__dict__.update(kwds)

    def keys(self):
        return self.__dict__.keys()

def RecycleBinW10(name):
    IFile_pack = 'QQQI'

    with open(name, 'rb') as file:
        content = file.read(calcsize(IFile_pack))
        data = unpack(IFile_pack, content)
        name = file.read(data[3]*2).decode('utf-8')

        metadata = IFile(
            header=data[0], size=data[1], timestamp=data[2],
            name_length=data[3], name=name)

        return metadata

def main():
    if len(sys.argv) == 2:
        metadata = RecycleBinW10(sys.argv[1])

        print('Header:\t\t{}\nSize:\t\t{}\nTimestamp:\t{}\nName length:\t{}\nName:\t\t{}'.format(
            metadata.header, metadata.size, metadata.timestamp, metadata.name_length, metadata.name
        ))


if __name__ == '__main__':
    main()
