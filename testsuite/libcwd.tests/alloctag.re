DEBUG   : Disabled
NOTICE  : Enabled
WARNING : Enabled
SYSTEM  : Enabled
MALLOC  : Enabled
BFD     : Disabled
MALLOC  : operator new\[\] \(size = 50\) = 0x[0-9a-f]*
MALLOC  : operator new \(size = 4\) = 0x[0-9a-f]*
MALLOC  : malloc\(33\) = 0x[0-9a-f]*
MALLOC  : malloc\(55\) = 0x[0-9a-f]*
MALLOC  : calloc\(22, 10\) = 0x[0-9a-f]*
MALLOC  : calloc\(55, 10\) = 0x[0-9a-f]*
MALLOC  : malloc\(11\) = 0x[0-9a-f]*
MALLOC  : realloc\(0x[0-9a-f]*, 1000\) = 0x[0-9a-f]*
MALLOC  : malloc\(66\) = 0x[0-9a-f]*
MALLOC  : realloc\(0x[0-9a-f]*, 1000\) = 0x[0-9a-f]*
MALLOC  : Allocated memory: 2912 bytes in 8 blocks\.
realloc   0x[0-9a-f]*          alloctag\.cc:71   int\[250\]; \(sz = 1000\)  Test of "\(int\*\)realloc\(mpi, 1000\)"
realloc   0x[0-9a-f]*          alloctag\.cc:65   void\*; \(sz = 1000\)  Test of "\(void\*\)realloc\(mp, 1000\)"
malloc    0x[0-9a-f]*          alloctag\.cc:59   int\[137\]; \(sz = 550\)  Test of "\(int\*\)calloc\(55, 10\)"
malloc    0x[0-9a-f]*          alloctag\.cc:56   void\*; \(sz = 220\)  Test of "\(void\*\)calloc\(22, 10\)"
malloc    0x[0-9a-f]*          alloctag\.cc:53   int\[13\]; \(sz = 55\)  Test of "\(int\*\)malloc\(55\)"
malloc    0x[0-9a-f]*          alloctag\.cc:50   void\*; \(sz = 33\)  Test of "\(void\*\)malloc\(33\)"
          0x[0-9a-f]*          alloctag\.cc:47   int; \(sz = 4\)  Test of "new int"
new[]     0x[0-9a-f]*          alloctag\.cc:44   char\[50\]; \(sz = 50\)  Test of "new char\[50\]"
MALLOC  : delete[] 0x[0-9a-f]*          alloctag\.cc:44   char\[50\]; \(sz = 50\)  Test of "new char\[50\]" 
MALLOC  : delete 0x[0-9a-f]*          alloctag\.cc:47   int; \(sz = 4\)  Test of "new int" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:50   void\*; \(sz = 33\)  Test of "\(void\*\)malloc\(33\)" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:53   int\[13\]; \(sz = 55\)  Test of "\(int\*\)malloc\(55\)" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:56   void\*; \(sz = 220\)  Test of "\(void\*\)calloc\(22, 10\)" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:59   int\[137\]; \(sz = 550\)  Test of "\(int\*\)calloc\(55, 10\)" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:65   void\*; \(sz = 1000\)  Test of "\(void\*\)realloc\(mp, 1000\)" 
MALLOC  : free\(0x[0-9a-f]*\)          alloctag\.cc:71   int\[250\]; \(sz = 1000\)  Test of "\(int\*\)realloc\(mpi, 1000\)" 
