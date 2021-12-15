using System;
using System.Collections.Generic;
using System.Text;

namespace lab2.untitled
{
	public interface ОкноУправления
	{
		bool ПросмотрДанных();

		bool ВыборДанных();

		bool РедактированиеДанных();

		void УдалениеДанных();

		bool ДобавлениеДанных();
	}
}
