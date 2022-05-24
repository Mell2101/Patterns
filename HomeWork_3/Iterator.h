#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<array>

class Cookies {
	std::string _nameCookies;
	int _col;
public:
	Cookies(int col, std::string name) : _col(col), _nameCookies(name) {}

	std::string getNameCookies() {
		return _nameCookies;
	}

	int getColCoolies() {
		return _col;
	}
};

class IIterator {
public:
	virtual bool hasNext() const = 0;
	virtual bool hasBack() const = 0;
	virtual Cookies next() = 0;
	virtual Cookies back() = 0;
	virtual ~IIterator() {};
};

class CookiesIteratorVector : public IIterator {
	std::vector<Cookies> _cook;
	int _position = 0;
public:
	CookiesIteratorVector(const std::vector<Cookies>& cookies) : _cook(cookies) {}

	bool hasNext() const override {
		return _position < _cook.size();
	}

	bool hasBack() const override {
		return _position == _cook.size();
	}

	Cookies next() override {
		Cookies cooks = _cook[++_position];
		return cooks;
	}

	Cookies back() override {
		Cookies cooks = _cook[--_position];
		return cooks;
	}
};

class CookiesIteratorArray : public IIterator {
	
	std::array<Cookies, 1000 > _cook;
	int _position = 0;
public:
	CookiesIteratorArray(const std::array<Cookies, 1000>& cookies) : _cook(cookies) {}

	bool hasNext() const override {
		return _position < _cook.size();
	}

	bool hasBack() const override {
		return _position == _cook.size();
	}

	Cookies next() override {
		Cookies cooks = _cook[++_position];
		return cooks;
	}

	Cookies back() override {
		Cookies cooks = _cook[--_position];
		return cooks;
	}
};

class CookiesIteratorDeque : public IIterator {

	std::deque<Cookies > _cook;
	int _position = 0;
public:
	CookiesIteratorDeque(const std::deque<Cookies>& cookies) : _cook(cookies) {}

	bool hasNext() const override {
		return _position < _cook.size();
	}

	bool hasBack() const override {
		return _position == _cook.size();
	}

	Cookies next() override {
		Cookies cooks = _cook[++_position];
		return cooks;
	}

	Cookies back() override {
		Cookies cooks = _cook[--_position];
		return cooks;
	}
};

class CookiesIteratorList : public IIterator {

	std::list<Cookies> _cook;
	int _position = 0;
public:
	CookiesIteratorList(const std::list<Cookies>& cookies) : _cook(cookies) {}

	bool hasNext() const override {
		return _position < _cook.size();
	}

	Cookies next() override {
		
		for (auto n : _cook) {
			Cookies cooks = n;
			return cooks;
		}
		
	}
};

class CookiesPuck1 {
	std::vector<Cookies> _cook;
	int _lastCol;
public:
	CookiesPuck1() {};

	void AddCookies(const std::string& name, const int& col) {
		_cook[++_lastCol] = Cookies(col, name);
	}
	std::vector<Cookies> getCookies() const {
		return _cook;
	}

	IIterator* createIterator() const {
		return new CookiesIteratorVector(_cook);
	}

};

class CookiesPuck2 {
	std::array<Cookies,1000> _cook;
	int _lastCol;
public:

	void AddCookies(const std::string& name, const int& col) {
		_cook[++_lastCol] = Cookies(col, name);
	}

	std::array<Cookies, 1000> getCookies() const {
		return _cook;
	}

	IIterator* createIterator() const {
		return new CookiesIteratorArray(_cook);
	}

};

class CookiesPuck3 {
	std::deque<Cookies> _cook;
	int _lastCol;
public:

	void AddCookies(const std::string& name, const int& col) {
		_cook[++_lastCol] = Cookies(col, name);
	}

	std::deque<Cookies> getCookies() const {
		return _cook;
	}

	IIterator* createIterator() const {
		return new CookiesIteratorDeque(_cook);
	}

};
