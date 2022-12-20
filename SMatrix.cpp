#include "SMatrix.h"

SMatrix::SMatrix(const std::string& strName, size_t unSize)
	: m_strName{ strName }, m_unSize{ unSize },
	m_vecData(m_unSize* m_unSize, 0) {}

int16_t SMatrix::operator() (size_t nRow, size_t nCol) const
{
	auto nIndex{ GetIndex(nRow, nCol) };
	if (nIndex == INVALID_INDEX)
	{
		throw std::runtime_error(GetErrInfo("Write", nRow, nCol));
	}
	return m_vecData.at(nIndex);
}

int16_t& SMatrix::operator()(size_t nRow, size_t nCol)
{
	auto nIndex{ GetIndex(nRow, nCol) };
	if (nIndex == INVALID_INDEX)
	{
		throw std::runtime_error(GetErrInfo("Write", nRow, nCol));
	}
	return m_vecData.at(nIndex);
}

std::string SMatrix::GetErrInfo(const char* cstrError, size_t nRow, size_t nCol) const
{
	std::stringstream stream;
	stream << cstrError << " access out of bounds for " << m_strName
		<< "[" << nRow << "][" << nCol << "]";
	return stream.str();
}

std::ostream& operator<<(std::ostream& out, const SMatrix& matrix)
{
	out << "\nMatrix[" << matrix.m_strName
		<< "] size[" << matrix.m_unSize << "] Contents:\n";
	for (size_t unRow = 0; unRow < matrix.m_unSize; unRow++)
	{
		for (size_t unCol = 0; unCol < matrix.m_unSize; unCol++)
		{
			out << std::setw(7) << matrix(unRow, unCol);
		}
		std::cout << '\n';
	}
	return out;
}

std::istream& operator>>(std::istream& in, SMatrix& matrix)
{
	std::cout << "Input Matrix[" << matrix.m_strName
		<< "] of size: " << matrix.m_unSize << '\n';
	for (size_t unRow = 0; unRow < matrix.m_unSize; unRow++)
	{
		for (size_t unCol = 0; unCol < matrix.m_unSize; unCol++)
		{
			std::cout << "Enter value for [" << unRow << "][" << unCol << "]: ";
			matrix(unRow, unCol) = Input::ReadNumber();
			std::cout << '\n';
		}
	}
	std::cout << "\n";
	return in;
}