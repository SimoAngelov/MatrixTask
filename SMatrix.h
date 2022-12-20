#pragma once
#include "Input.h"

/// <summary>
/// Two-dimensional array.
/// </summary>
struct SMatrix
{
public:
	/// <summary>
	/// Invalid index value.
	/// </summary>
	static constexpr int16_t INVALID_INDEX{ -1 };

public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	/// <param name="unSize"> Matrix size. </param>
	SMatrix(const std::string& strName, size_t unSize);
	virtual ~SMatrix() = default;

	/// <summary>
	/// Retrieve the matrix size.
	/// </summary>
	/// <returns> m_unSize. </returns>
	size_t GetSize() const { return m_unSize; }

	/// <summary>
	/// Get element from the matrix.
	/// </summary>
	/// <param name="nRow"> Matrix row. </param>
	/// <param name="nCol"> Matrix col. </param>
	/// <returns> The specified element, if the coordinates are valid.
	/// Otherwise return ERR_VALUE. </returns>
	int16_t operator() (size_t nRow, size_t nCol) const;

	/// <summary>
	/// Set an element from the matrix.
	/// </summary>
	/// <param name="nValue"> Value to be set. </param>
	/// <param name="nRow"> Matrix row. </param>
	/// <param name="nCol"> Matrix column. </param>
	/// <returns> True, if the value was set successfully. </returns>
	int16_t& operator()(size_t nRow, size_t nCol);

	/// <summary>
	/// Output stream operator overload.
	/// Print the contents of the matrix to the console.
	/// </summary>
	/// <param name="out"> Output stream to be populated. </param>
	/// <param name="matrix"> Matrix to be output to the console. </param>
	/// <returns> The output stream object. </returns>
	friend std::ostream& operator<<(std::ostream& out, const SMatrix& matrix);

	/// <summary>
	/// Input stream operator overload.
	/// Fill the matrix with data.
	/// </summary>
	/// <param name="in"> Input stream for data population. </param>
	/// <param name="matrix"> Output parameter. Matrix to be filled with data. </param>
	/// <returns> The input stream object. </returns>
	friend std::istream& operator>>(std::istream& in, SMatrix& matrix);

private:

	/// <summary>
	/// Retrieve the array index from the specified row and column.
	/// </summary>
	/// <param name="nRow"> Matrix row. </param>
	/// <param name="nCol"> Matrix column. </param>
	/// <returns> The matrix index. </returns>
	constexpr int16_t GetIndex(size_t nRow, size_t nCol) const
	{
		// Check if the indices are valid.
		if (nRow >= m_unSize || nCol >= m_unSize)
		{
			return INVALID_INDEX;
		}
		// Return the array index, based on the row and column.
		return m_unSize * nRow + nCol;
	}

	/// <summary>
	/// Retrieve error information.
	/// </summary>
	/// <param name="cstrError"> Error type. </param>
	/// <param name="nRow"> Row that triggered the error. </param>
	/// <param name="nCol"> Column that triggered the error. </param>
	/// <returns> Error message. </returns>
	std::string GetErrInfo(const char* cstrError,
		size_t nRow,
		size_t nCol) const;

private:
	/// <summary>
	/// Matrix name.
	/// </summary>
	std::string m_strName;

	/// <summary>
	/// Matrix size.
	/// </summary>
	size_t m_unSize;

	/// <summary>
	/// Matrix data.
	/// </summary>
	std::vector<int16_t> m_vecData;
};