#include <libcw/sysd.h>
#include <unistd.h>
#include <libcw/debug.h>

namespace libcw {
  namespace debug {
    namespace channels {
      namespace dc {
	channel_ct generate("GENERATE");
      }
    }
  }
}

void generate_tables(void)
{
  write(1, "<sleeping>", 10);
  sleep(1);
  Dout( dc::generate, "Inside generate_tables()" );
  std::cout << std::flush;
  write(1, "<sleeping>", 10);
  sleep(1);
  Dout( dc::generate, "Leaving generate_tables()" );
  std::cout << std::flush;
  return;
}

int main(void)
{
  Debug( check_configuration() );
  Debug( libcw_do.set_ostream(&std::cout) );

  // Select channels
  ForAllDebugChannels( if (!debugChannel.is_on()) debugChannel.on(); );

  // Turn debug object on
  Debug( libcw_do.on() );

  //Debug( dc::io.off() );
  Dout( dc::notice|flush_cf|continued_cf, "Generating tables part1... " );
  generate_tables();
  Dout( dc::continued, "part2... " );
  generate_tables();
  Dout( dc::finish, "done" );
}
