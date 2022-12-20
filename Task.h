#pragma once
#include "SMatrix.h"

/// <summary>
/// Handle task execution.
/// </summary>
class Task
{
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	/// <param name="strAuthor"> Task author. </param>
	/// <param name="strDescription"> Task description. </param>
	Task(const std::string& strAuthor,
		const std::string& strDescription);
	virtual ~Task() = default;

	/// <summary>
	/// Run this task.
	/// </summary>
	void Run();

private:
	/// <summary>
	/// Print task information.
	/// </summary>
	void PrintInfo();

	/// <summary>
	/// Input data.
	/// </summary>
	void InputData();

	/// <summary>
	/// Output Data.
	/// </summary>
	void OutputData();

	/// <summary>
	/// Process array A.
	/// </summary>
	void ProcessArrayA();

private:
	/// <summary>
	/// Task author.
	/// </summary>
	std::string m_strAuthor;

	/// <summary>
	/// Task description.
	/// </summary>
	std::string m_strDescription;

	/// <summary>
	/// Size of the array N.
	/// </summary>
	size_t m_unSize;

	/// <summary>
	/// Lower bound K.
	/// </summary>
	int16_t m_nLowerBound;

	/// <summary>
	/// Upper bound L.
	/// </summary>
	int16_t m_nUpperBound;

	/// <summary>
	/// Number of changes made to array A.
	/// </summary>
	size_t m_unArrayChanges;

	/// <summary>
	/// Array A.
	/// </summary>
	SMatrix m_arrayA;

	/// <summary>
	/// Array B.
	/// </summary>
	SMatrix m_arrayB;
};

