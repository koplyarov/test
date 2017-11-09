#ifndef TEST_CORE_TESTENGINE_HPP
#define TEST_CORE_TESTENGINE_HPP


#include <memory>
#include <string>

#include <test/Location.hpp>


namespace test
{

    struct ITestResultsListener
    {
        virtual ~ITestResultsListener() { }

        virtual void RunningTest(const std::string& testName, const Location& location) = 0;
        virtual void TestSucceeded(const std::string& testName, const Location& location) = 0;
        virtual void TestFailed(const std::string& testName, const Location& location) = 0;
        virtual void ReportWarning(const std::string& testName, const Location& location, const std::string& message) = 0;
        virtual void AssertionFailed(const std::string& testName, const Location& location, const std::string& message) = 0;
    };
    using ITestResultsListenerPtr = std::unique_ptr<ITestResultsListener>;


    class TestEngine
    {
    private:
        ITestResultsListenerPtr     _resultsListener;

    public:
        TestEngine();

        const ITestResultsListenerPtr& GetListener() const { return _resultsListener; }
    };

}

#endif
