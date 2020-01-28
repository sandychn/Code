# Time  : 32 ms (94.73%)
# Memory: 13.2 MB (57.66%)

class Solution:
    def simplifyPath(self, path: str) -> str:
        path_list = []
        for name in path.split('/'):
            if name == '..':
                if len(path_list) > 0: path_list.pop()
            elif name != '.' and name != '':
                path_list.append(name)
        return '/' + '/'.join(path_list)
