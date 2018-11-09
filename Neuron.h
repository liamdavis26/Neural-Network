#ifndef _NEURON_H_
#define _NEURON_H_


class Neuron
{
private:
	float m_fThreshold, m_fWeight[2], m_fIn[2], m_fPush, m_fOutput, m_fLearnRate, m_fDesired;
public:
	Neuron();
	float GetInput(float _fIn1, float _fIn2);
	float Process(void);
	float GetOut(void);
	void PrintWeight(void);
};

#endif