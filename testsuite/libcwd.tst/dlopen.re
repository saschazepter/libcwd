// input lines 2
// output till Loading debug info from \./module\.so
(.*
)*
BFD     : Loading debug info from \./module\.so \(0x[a-f0-9]*\) \.\.\. done \([0-9]* symbols\)
// input lines 2
// output till malloc\(310\)
(.*
)*
MALLOC  : malloc\(310\) = <unfinished>
BFD     :     address 0x[0-9a-f]* corresponds to module.cc:19
MALLOC  : <continued> 0x[0-9a-f]*
MALLOC  : malloc\(300\) = <unfinished>
BFD     :     address 0x[0-9a-f]* corresponds to module.cc:10
MALLOC  : <continued> 0x[0-9a-f]*
MALLOC  : Allocated memory: [0-9]* bytes in [0-9]* blocks\.
malloc    0x[0-9a-f]*            module\.cc:10   void\*; \(sz = 300\)  Allocated inside static_test_symbol
malloc    0x[0-9a-f]*            module\.cc:19   void\*; \(sz = 310\)  Allocated inside global_test_symbol
BFD     : Warning: Address 0x[0-9a-f]* in section \.text of object file "libstdc.*"
          does not have a line number, perhaps the unit containing the function
          `streambuf::streambuf\(int\)' wasn't compiled with flag -(g|ggdb)\?
          0x[0-9a-f]* *streambuf::streambuf\(int\) <unknown type>; \(sz = [0-9]*\) 
// input lines 2
// output till ^NOTICE
(malloc    0x[0-9a-f]* *(dl-[a-z]*\.c|stl_alloc\.h|specific\.c|dlerror\.c|eh_globals\.cc):[0-9]* *<unknown type>; \(sz = [0-9]*\) 
)*
NOTICE  : Finished
