from reverse_integer import Solution



def TestReverseInteger():
    solut = Solution()
    assert solut.reverse(-123) == -321
    assert solut.reverse(123) == 321
    assert solut.reverse(120) == 21


if __name__ == "__main__":
    TestReverseInteger()