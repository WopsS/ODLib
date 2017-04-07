#include <ODLib/ODLib.hpp>
#include <ODLib/Logger/Logger.hpp>

ODLib::Logger::Logger::Logger(ODLib::Logger::Settings Settings)
    : m_settings(Settings)
    , m_nextRotation(GetNextRotation())
{
    CreateFileIfNeeded();
}

ODLib::Logger::Logger::~Logger()
{
    m_file.close();
}

void ODLib::Logger::Logger::WriteLine(const ODLib::Logger::Record::Record& Record)
{
    if (m_settings.DailyRotation == true && std::chrono::system_clock::now() >= m_nextRotation)
    {
        CreateFileIfNeeded();
        m_nextRotation = GetNextRotation();
    }

    auto Result = L"[" + ODLib::Logger::Record::Level::ToString(Record.GetLevel()) + L"] " + Record.GetText();

    std::wcout << Result << std::flush;

    m_file << L"[" << Record.GetTime() << L"] " << Result;
    m_file.flush();
}

void ODLib::Logger::Logger::CreateFileIfNeeded()
{
    if (m_file.is_open() == true)
    {
        m_file.close();
        m_file.clear();
    }

    // Format the time for the file.
    std::ostringstream Result;

    auto Time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Result << std::put_time(std::localtime(&Time), m_settings.FileName.c_str());

    auto FileName = Result.str();

    // Create the directory if needed.
    std::experimental::filesystem::path Path(FileName);

    auto FileDirectory = Path.parent_path();

    if (FileDirectory.empty() == false && std::experimental::filesystem::exists(FileDirectory) == false)
    {
        std::experimental::filesystem::create_directories(FileDirectory);
    }

    m_file.open(FileName, m_settings.FileMode);

    // Move the input position indicator to the end of the file.
    m_file.seekg(0, std::ios::end);

    // Is the file content empty?
    if (m_file.tellg() > 0)
    {
        // Append a line to separate a the old content from the new content.
        m_file << std::endl;
        m_file << L"-----------------------------------------------------" << std::endl;
    }
}

std::chrono::system_clock::time_point ODLib::Logger::Logger::GetNextRotation()
{
    auto Now = std::chrono::system_clock::now();
    auto Time = std::chrono::system_clock::to_time_t(Now);
    auto Date = std::localtime(&Time);

    // Set midnight time.
    Date->tm_hour = 0;
    Date->tm_min = 0;
    Date->tm_sec = 0;

    // Calculate next rotation.
    auto NextRotation = std::chrono::system_clock::from_time_t(std::mktime(Date));
    
    if (NextRotation > Now)
    {
        return NextRotation;
    }
    else
    {
        return NextRotation + 24h;
    }
}
