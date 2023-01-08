#pragma once

template<typename Q>



class Triple
{
	Q f;
	Q s;
	Q t;
public:
	Triple() {};

	Q getFirst() {
		return f;
	}
	Q getSecond() {
		return s;
	}
	Q getThird() {
		return t;
	}

	void setFirst(Q first) {
		f = first;
	}
	void setSecond(Q second) {
		s = second;
	}
	void setThird(Q third) {
		t = third;
	}

};
