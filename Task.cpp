#include "Task.h"

Task::Task(const std::string& strAuthor, const std::string& strDescription)
	: m_strAuthor{ strAuthor }, m_strDescription{ strDescription },
	m_unSize{ 0 }, m_nLowerBound{ 0 }, m_nUpperBound{ 0 }, m_unArrayChanges{ 0 },
	m_arrayA{ "A", m_unSize }, m_arrayB{ "B", m_unSize }
{
}

void Task::Run()
{
	PrintInfo();
	InputData();
	OutputData();
	ProcessArrayA();
}

void Task::PrintInfo()
{
	std::cout << "Task Author: " << m_strAuthor
		<< ",\n Description: " << m_strDescription << '\n';
}

void Task::InputData()
{
	std::cout << "Enter N: ";
	m_unSize = Input::ReadNumber();

	std::cout << "\nEnter K: ";
	m_nLowerBound = Input::ReadNumber();

	std::cout << "\nEnter L: ";
	m_nUpperBound = Input::ReadNumber();

	// If K is larger than L, throw an error.
	if (m_nLowerBound >= m_nUpperBound)
	{
		std::stringstream stream;
		stream << "K(" << m_nLowerBound << ") is larger than L("
			<< m_nUpperBound << ")!";
		throw std::runtime_error(stream.str());
	}

	m_arrayA = { "A", m_unSize };
	m_arrayB = { "B", m_unSize };
	std::cin >> m_arrayA >> m_arrayB;
}

void Task::OutputData()
{
	std::cout << "N: " << m_unSize
		<< ", K: " << m_nLowerBound
		<< ", L: " << m_nUpperBound
		<< m_arrayA << m_arrayB << '\n';
}

void Task::ProcessArrayA()
{
	m_unArrayChanges = 0;
	for (size_t unRow = 0; unRow < m_arrayA.GetSize(); unRow++)
	{
		for (size_t unCol = 0; unCol < m_arrayA.GetSize(); unCol++)
		{
			// Retrieve the sum of the corresponding elements from A and B.
			auto nSum{ m_arrayA(unRow, unCol) + m_arrayB(unRow, unCol) };

			// Check if the sum is even.
			bool isEven{ nSum % 2 == 0 };

			// Check if the sum is in the range [K, L].
			bool isInRange{ nSum >= m_nLowerBound && nSum <= m_nUpperBound };

			// If the sum is even and in range, zero out the corresponding
			// element in A.
			if (isEven && isInRange)
			{
				m_arrayA(unRow, unCol) = 0;

				// Increment the number of array changes.
				m_unArrayChanges++;
			}
		}
	}
	std::cout << "After processing the number of changes is "
		<< m_unArrayChanges << m_arrayA;
}
