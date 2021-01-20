vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    for(string& s : dictionary)
        sort(s.begin(), s.end());
    map<string, int> M;
    for(string& s : dictionary)
        M[s]++;
    int n = dictionary.size();
    vector<int> Q(query.size());
    for(string& s : query)
        sort(s.begin(), s.end());
    for(int i = 0; i < query.size(); i++){
        Q[i] = M[query[i]];
    }
    return Q;
}
