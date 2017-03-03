#pragma once

#include <QDebug>
#include <QJsonObject>
#include <QString>

class utils
{
private:
	struct myStruct
	{
		QString hashIndex;
		bool operator() (const QJsonObject& lhs, const QJsonObject& rhs)
		{
			return lhs[hashIndex].toString() < rhs[hashIndex].toString();
		}
	};

public:
	/// <summary>
	/// Object variables.
	/// </summary>
	struct QuestionBatch
	{
		QString title;
		QString description;
		size_t bIndex;
	};

	struct CompQuestionBatchByTitle
	{
		bool operator() (const utils::QuestionBatch& lhs, const utils::QuestionBatch& rhs)
		{
			return lhs.title < rhs.title;
		}
	};

	struct CompQuestionBatchByTitleBSearch
	{
		bool operator() (const QString& s, const utils::QuestionBatch& i)
		{
			return s < i.title;
		}

		bool operator() (const utils::QuestionBatch& i, const QString& s)
		{
			return i.title < s;
		}
	};

	struct CompQJsonObjectByTitle
	{
		bool operator() (const QString& s, const QJsonObject& i)
		{
			return s < i["title"].toString();
		}

		bool operator() (const QJsonObject& i, const QString& s)
		{
			return i["title"].toString() < s;
		}
	};

	static QString readFile(const QString& directory);

	/// <summary>
	/// Quicksort algorithm method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template<typename Iterator>
	static inline void quickSort(Iterator begin, Iterator end)
	{
		if (end - begin < 2)
			return;
		Iterator l = begin;
		Iterator r = end - 1;
		
		// find pivot.
		Iterator pivot = std::next(begin, (std::distance(begin, end) / 2));

		while (l != r)
		{
			// Find the lowest bound number to swap.
			while (*l < *pivot) 
				++l;
			while (*r >= *pivot && l < r) 
				--r;

			// Do the swap.
			if (pivot == l) 
				pivot = r;
			std::swap(*l, *r);
		}

		// Move pivot to the position.
		std::swap(*pivot, *l);

		// Sort left.
		quickSort(begin, l);
		// Sort right.
		quickSort(l + 1, end);
	};

	/// <summary>
	/// Binary search algorithm method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template<typename Iterator, class T>
	static inline Iterator binarySearch(Iterator begin, Iterator end, T value)
	{
		Iterator left = begin;
		Iterator right = end;
		while (left <= right) 
		{
			Iterator middle = std::next(left, (std::distance(left, right) / 2));
			if (*middle == value)
				return middle;
			else if (*middle > value)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return nullptr;
	}

	static QString readBinaryFile(const QString& dir);

	/// <summary>
	/// Print all elements of simple array method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template <class Iterator>
	static inline void printArray(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			qDebug() << *begin << ' ';
			++begin;
		}
		qDebug() << "\n";
	};

	/// <summary>
	/// Print all reference of simple array method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	template <class Iterator>
	static inline void printArrayReference(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			qDebug() << begin << ' ';
			++begin;
		}
		qDebug() << "\n";
	};

	/// <summary>
	/// Copy over reference of array to pointer method.
	/// </summary>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	/// <param name="arr"></param>
	template <class RAI, class T>
	static inline void copyOverReference(RAI begin, RAI end, T& arr)
	{
		size_t index = 0;
		while (begin != end)
		{
			arr[index] = begin;
			++begin;
			index++;
		}
	};

	static myStruct compareQJsonObjectBy(const QString& hashIndex);

private:
};

