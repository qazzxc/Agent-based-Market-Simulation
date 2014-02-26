
#include <stdio.h>
#include <stdlib.h>

#include "utl.h"

struct Agent
{
  double bid;
  double ask;
  double spread;
  void (*refresh)();
  void (*set)();
};
typedef struct Agent Agent;

void
refresh_price(Agent * agent)
{
  /*�����Z�ɏC�� 1��œ������̂�Spread�̃Ё�1%�Ő��K���� 1% */
  double dp = grand() * agent->spread * 0.01 ; 
  /*�����Z�ɏC�� 1��œ������̂�ask�̃Ё�0.05%�Ő��K���� 
  double dp = grand() * agent->bid * 0.0005 ;*/
  agent->ask += dp;
  agent->bid += dp;
}

void
set_price(Agent * agent, double price)
{
  /* �σX�v���b�hVer Spread 1% ���̕ϓ��͂���10% 
  agent->spread = price * ( 0.01 + (0.01*0.1*grand()));
  */
  /* Spread 1% 
  agent->spread = price * ( 0.01 );
  */
  agent->ask = price + agent->spread * 0.5;
  agent->bid = price - agent->spread * 0.5;

}

void
init_agent(Agent * agent)
{
  agent->ask = 100;
  agent->spread = agent->ask * 0.01;
  agent->bid = agent->ask - agent->spread;
  agent->refresh = refresh_price;
  agent->set = set_price;
}

void
init_agents(Agent * agents, int num_agents)
{
  Agent * agent = agents;
  for(; num_agents--; ++agent)
  {
    init_agent(agent);
    agent->refresh(agent);
  }
}

void
minmax(double * min_ask, double * max_bid, Agent * agents, int num_agents)
{
  double * bids;
  double * asks;
  bids = malloc(sizeof(double) * num_agents);
  asks = malloc(sizeof(double) * num_agents);

  double * bid;
  double * ask;
  Agent * agent = agents;
  int i;
  for(bid = bids, ask = asks, i = num_agents; i--; ++agent, ++bid, ++ask)
  {
    *bid = agent->bid;
    *ask = agent->ask;
  }

  *min_ask = min(asks, num_agents);
  *max_bid = max(bids, num_agents);
  free(bids);
  free(asks);
}

