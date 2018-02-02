#include <odlib/odlib.hpp>
#include <odlib/logger/logger.hpp>
#include <odlib/utils/string.hpp>

odlib::logger::logger::logger(odlib::logger::settings settings)
    : m_settings(settings)
    , m_next_rotation(get_next_rotation())
{
    create_file_if_needed();
}

odlib::logger::logger::~logger()
{
    m_file.close();
}

void odlib::logger::logger::write_line(const odlib::logger::record::record& record)
{
    if (m_settings.daily_rotation == true && std::chrono::system_clock::now() >= m_next_rotation)
    {
        create_file_if_needed();
        m_next_rotation = get_next_rotation();
    }

    auto result = L"[" + odlib::logger::record::level::to_string(record.get_level()) + L"] " + record.get_text();

    std::wcout << result << std::flush;

    m_file << L"[" << record.get_time() << L"] " << result;
    m_file.flush();
}

void odlib::logger::logger::create_file_if_needed()
{
    if (m_file.is_open() == true)
    {
        m_file.close();
        m_file.clear();
    }

    // Format the time for the file.
    std::wostringstream result;

    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    result << std::put_time(std::localtime(&time), m_settings.file_name.c_str());

    auto file_name = result.str();

    // Create the directory if needed.
    std::experimental::filesystem::path Path(file_name);

    auto file_directory = Path.parent_path();

    if (file_directory.empty() == false && std::experimental::filesystem::exists(file_directory) == false)
    {
        std::experimental::filesystem::create_directories(file_directory);
    }

    m_file.open(utils::string::wide_to_utf8(file_name), m_settings.file_mode);

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

std::chrono::system_clock::time_point odlib::logger::logger::get_next_rotation()
{
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    auto date = std::localtime(&time);

    // Set midnight time.
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;

    // Calculate next rotation.
    auto next_rotation = std::chrono::system_clock::from_time_t(std::mktime(date));
    
    if (next_rotation > now)
    {
        return next_rotation;
    }
    else
    {
        return next_rotation + 24h;
    }
}
