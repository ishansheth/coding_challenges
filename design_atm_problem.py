# https://leetcode.com/problems/design-an-atm-machine/

class ATM:
    def __init__(self):
        self.note_idx = {}
        self.note_idx[20] = 0
        self.note_idx[50] = 1
        self.note_idx[100] = 2
        self.note_idx[200] = 3
        self.note_idx[500] = 4
        self.storage = [0] * 5

    def deposit(self, banknotesCount):
        for idx, val in enumerate(banknotesCount):
            self.storage[idx] += val

    def tryWithDenomination(self, amount, denom_val, result):
        required = amount // denom_val
        if self.storage[self.note_idx[denom_val]] >= required:
            result[self.note_idx[denom_val]] = required
            self.storage[self.note_idx[denom_val]] -= required
            amount = amount % denom_val
        elif self.storage[self.note_idx[denom_val]] > 0:
            result[self.note_idx[denom_val]] = self.storage[self.note_idx[denom_val]]
            amount = amount - (denom_val * self.storage[self.note_idx[denom_val]])
            self.storage[self.note_idx[denom_val]] = 0
        else:
            return [-1]

        return amount

    def withdraw(self, amount):
        res = [0] * 5
        res_amount = amount
        temp_storage_copy = self.storage[:]

        while res_amount > 0:
            try_d_val = False
            for d_value in [500, 200, 100, 50, 20]:
                if res_amount >= d_value and self.storage[self.note_idx[d_value]] > 0:
                    try_d_val = True
                    res_amount = self.tryWithDenomination(res_amount, d_value, res)
                    if res_amount == [-1]:
                        self.storage = temp_storage_copy[:]
                        return [-1]

            if not try_d_val:
                self.storage = temp_storage_copy[:]
                return [-1]

        return res


obj = ATM()
obj.deposit([0,0,0,2,2])
notes = obj.withdraw(1300)
print(notes)
obj.deposit([0,1,0,1,1])
notes = obj.withdraw(600)
print(notes)
notes = obj.withdraw(550)
print(notes)


