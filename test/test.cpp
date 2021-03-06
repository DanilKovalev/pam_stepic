#include "CapabilityTest.h"
#include "SecCompTest.h"
#include "ConfigTest.h"
#include "CommandLineTest.h"

#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/CompilerOutputter.h>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CapabilityTest, "CapabilityTest" );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( SecCompTest, "SecCompTest" );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( ConfigTest, "ConfigFileTest" );
CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( CommandLineTest, "CommandLineTest" );

int main()
{
    CppUnit::Test *capability_test =
            CppUnit::TestFactoryRegistry::getRegistry("CapabilityTest").makeTest();

    CppUnit::Test *seccomp_test =
            CppUnit::TestFactoryRegistry::getRegistry("SecCompTest").makeTest();

    CppUnit::Test *config_test =
            CppUnit::TestFactoryRegistry::getRegistry("ConfigFileTest").makeTest();

    CppUnit::Test *cli_test =
            CppUnit::TestFactoryRegistry::getRegistry("CommandLineTest").makeTest();

    CppUnit::TextTestRunner runner;

    runner.setOutputter( new CppUnit::CompilerOutputter(&runner.result(), std::cerr ) );
    runner.addTest(capability_test);
    runner.addTest(seccomp_test);
    runner.addTest(config_test);
    runner.addTest(cli_test);

    return !runner.run("",false);
}