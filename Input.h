#pragma once
#include <iostream> // For std::cin and std::cout
#include <vector> // For std::vector
#include <string> // For std::string
#include <sstream> // For std::stringstream
#include <cstdint> // For int16_t
#include <iomanip> // For std::setw

/// <summary>
/// Read and handle input from the console.
/// </summary>
class Input
{
public:
	/// <summary>
	/// Read a number from the console.
	/// </summary>
	/// <returns> The input number. </returns>
	static int16_t ReadNumber()
	{
		// Define the accepeted number range as [-MAX_RANGE, MAX_RANGE].
		static constexpr uint16_t MAX_RANGE{ 1000 };
		int16_t n{ 0 };
		try
		{
			std::string strInput{ "" };
			std::getline(std::cin, strInput);
			n = std::stoi(strInput);
			if (n < -MAX_RANGE || n > MAX_RANGE)
			{
				std::stringstream stream;
				stream << "ReadNumber threw invalid number! n(" << n
					<< ") is not in range: [" << -MAX_RANGE << ", " << MAX_RANGE << "]!";
				throw std::runtime_error(stream.str());
			}
		}
		catch (std::invalid_argument const& ex)
		{
			std::stringstream stream;
			stream << "ReadNumber threw std::invalid_argument::what(): " << ex.what() << '\n';
			throw std::runtime_error(stream.str());
		}
		catch (std::out_of_range const& ex)
		{
			std::stringstream stream;
			stream << "ReadNumber threw std::out_of_range::what(): " << ex.what() << '\n';
			throw std::runtime_error(stream.str());
		}
		return n;
	}
};