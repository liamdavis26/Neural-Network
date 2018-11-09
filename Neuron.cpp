#include "Neuron.h"
#include <iostream>

Neuron::Neuron()
{
	m_fPush = 0.0f;
	m_fOutput = 0.0f;
	m_fWeight[0] = 0.5f;
	m_fWeight[1] = -0.5f;
	m_fThreshold = 0.2f;
	m_fDesired = 0.0f;
	m_fLearnRate = 0.1f;
}

float Neuron::GetInput(float _fIn1, float _fIn2)
{
	m_fIn[0] = _fIn1;
	m_fIn[1] = _fIn2;

	if((_fIn1 == 1.0f) && (_fIn2 == 1.0f))
	{
		m_fDesired = 1.0f;
	}
	else
	{
		m_fDesired = 0.0f;
	}
	return Process();
}

float Neuron::Process(void)
{
	float fError = 0.0f;
	for(int i = 0; i < 2; i++)
	{
		m_fOutput = m_fOutput + (m_fIn[i] * m_fWeight[i]);
	}

	if(m_fOutput >= m_fThreshold)
	{
		m_fPush = 1.0f;
	}
	else if(m_fOutput < m_fThreshold)
	{
		m_fPush = 0.0f;
	}

	fError = m_fDesired - m_fPush;

	if(fError < 0)
	{
		m_fWeight[0] = m_fWeight[0] + (m_fLearnRate * m_fIn[0] * fError);
	}
	else if(fError > 0)
	{
		m_fWeight[1] = m_fWeight[1] + (m_fLearnRate * m_fIn[1] * fError);
	}
	m_fOutput = 0;

	return m_fPush;
}

void Neuron::PrintWeight(void)
{
	std::cout << m_fWeight[0] << std::endl << m_fWeight[1];
}