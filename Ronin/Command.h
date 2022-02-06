#pragma once
class Command{
public:
	virtual string CommandName() const = 0;
	virtual void  CommandCall(string) const = 0;
};