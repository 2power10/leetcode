__author__ = 'yzheng'

class Solution(object):
    def wordPattern(self, pattern, str):
        if pattern is None or str is None:
            return False
        if len(pattern) == 0 or len(str) == 0:
            return False

        pattern_arr = pattern2Arr(pattern)
        str_arr = str2Arr(str)

        pattern_dict = arr2dict(pattern_arr)
        str_dict = arr2dict(str_arr)

        pattern_signature = gen_signature(pattern_arr, pattern_dict)
        str_signature = gen_signature(str_arr, str_dict)

        return pattern_signature == str_signature


def gen_signature(arr, id_dict):
    signature = ''
    for item in arr:
        signature += id_dict[item]
    return signature

def arr2dict(arr):
    if arr is None or len(arr) == 0:
        return {}
    item_id_dict = {}
    i = 0
    for item in arr:
        if not item_id_dict.has_key(item):
            item_id_dict[item] = str(i)
            i += 1
    return item_id_dict

def pattern2Arr(pattern):
    if pattern is None:
        return []

    i = 0
    l = len(pattern)
    arr = []
    while i < l:
        arr.append(pattern[i])
        i += 1
    return arr

def str2Arr(str):
    if str is None:
        return []
    return str.split()


if __name__ == "__main__":
    s = Solution()
    s.wordPattern('abba', 'dog cat cat dog')
