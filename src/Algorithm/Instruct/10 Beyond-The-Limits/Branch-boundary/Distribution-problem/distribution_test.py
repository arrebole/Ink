from distribution import distribution


def TestDistribution():
    data = [[9,2,7,8],[6,4,3,7],[5,8,1,8],[7,6,9,4]]
    assert distribution(data) == 13

TestDistribution()