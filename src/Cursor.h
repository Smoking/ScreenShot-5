#pragma once

#include "Const.h"
class Cursor
{
public:
	Cursor(void);
	virtual ~Cursor(void);	
	void	change(long n);
protected:
	void	empty();
private:
	HCURSOR		cur_;		//��ǰָ��
	long		state_;		//����״̬
};
