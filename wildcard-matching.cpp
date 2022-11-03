#include <vector>
#include <string>
#include <set>

using namespace std;

enum EdgeType
  {
    Edge_Eps = -2,
    Edge_Any = -1
  };

struct ENFAedge
{
  size_t dst;
  char label;
};

using ENFAnode = set<ENFAedge>;
using ENFAclosure = set<size_t>;

struct ENFA
{
  size_t start, end;
  vector<ENFAnode> nodes;
  vector<ENFAclosure> closures;
};

bool
operator<(ENFAedge e0, ENFAedge e1)
{
  if (e0.label == e1.label)
    return e0.dst < e1.dst;
  else
    return e0.label < e1.label;
}

void
push_edge(ENFA *nfa, char label, size_t src_idx, size_t dst_idx)
{
  nfa->nodes[src_idx].insert({ dst_idx, label });
}

size_t
push_node(ENFA *nfa)
{
  size_t node_idx = nfa->nodes.size();

  nfa->nodes.push_back({ });

  return node_idx;
}

ENFA
parse_pattern(const char *str)
{
  ENFA nfa;
  nfa.start = nfa.end = 0;
  nfa.nodes.reserve(32);
  nfa.nodes.push_back({ });

  while (*str != '\0')
    {
      if (*str == '*')
        {
          size_t const subexpr_start = nfa.end;
          size_t subexpr_end = push_node(&nfa);
          size_t end = push_node(&nfa);

          push_edge(&nfa, Edge_Any, subexpr_start, subexpr_end);
          push_edge(&nfa, Edge_Eps, subexpr_end, subexpr_start);
          push_edge(&nfa, Edge_Eps, subexpr_start, end);
          push_edge(&nfa, Edge_Eps, subexpr_end, end);
          nfa.end = end;

          while (*++str == '*')
            ;
        }
      else
        {
          char label = *str == '?' ? (char)Edge_Any : *str;
          size_t end = push_node(&nfa);

          push_edge(&nfa, label, nfa.end, end);
          nfa.end = end;
          ++str;
        }
    }

  nfa.closures.resize(nfa.nodes.size());

  return nfa;
}

void
compute_closures_aux(ENFA *nfa, vector<bool> &visited, size_t node_idx)
{
  visited[node_idx] = true;

  ENFAnode *edges = &nfa->nodes[node_idx];

  for (auto node: *edges)
    if (!visited[node.dst] && node.label == Edge_Eps)
      compute_closures_aux(nfa, visited, node.dst);

  ENFAclosure *closure = &nfa->closures[node_idx];
  closure->insert(node_idx);

  for (auto node: *edges)
    {
      if (node.label == Edge_Eps)
        {
          // Copy the closure of a child, because we don't want to modify it.
          auto src = nfa->closures[node.dst];
          closure->merge(src);
        }
    }
}

void
compute_closures(ENFA *nfa)
{
  vector<bool> visited;
  visited.resize(nfa->nodes.size());

  for (size_t i = 0; i < nfa->nodes.size(); i++)
    if (!visited[i])
      compute_closures_aux(nfa, visited, i);
}

void
insert_closure(std::set<size_t> &set, std::set<size_t> &closure)
{
  set.insert(closure.begin(), closure.end());
}

class Solution
{
public:
  bool
  isMatch(string s, string p)
  {
    ENFA nfa = parse_pattern(p.c_str());
    compute_closures(&nfa);

    set<size_t> front, back;

    insert_closure(front, nfa.closures[nfa.start]);

    for (char ch: s)
      {
        for (auto node: front)
          {
            auto *set = &nfa.nodes[node];
            auto end = set->end();
            auto it = set->lower_bound({ 0, ch });

            for (; it != end && it->label == ch; it++)
              insert_closure(back, nfa.closures[it->dst]);

            it = set->lower_bound({ 0, Edge_Any });

            for (; it != end && it->label == Edge_Any; it++)
              insert_closure(back, nfa.closures[it->dst]);
          }

        front.clear();
        front.swap(back);
      }

    for (auto node: front)
      if (node == nfa.end)
        return true;

    return false;
  }
};
