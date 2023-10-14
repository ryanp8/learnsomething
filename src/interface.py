from collections import deque

class Exchange:
    # implement this!

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.initialBalance = initialBalance
        self.balances = {}
        self.buy = {}
        self.sell = {}

    # trade:
    #     account
    #     type
    #     name
    #     shares
    #     price
    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """

        if trade.account not in self.balances:
            self.balances[trade.account] = self.initialBalance

        if trade.type == "b" and self.balances[trade.account] < trade.shares * trade.price:
            return []

        orders = self.buy if trade.type == "b" else self.sell
        target_orders = self.sell if trade.type == "b" else self.buy

        n = trade.name
        s = trade.shares

        match = []

        if n in target_orders:
            q = target_orders[n]
            while q and s:
                count_shares = min(trade.shares, q[0].shares * q[0].price // trade.price)
                q[0].shares -= count_shares
                s -= count_shares
                match.append(q[0])
                if q[0].shares == 0:
                    q.popleft()
            if match:
                match.append(trade)
            if s > 0:
                if n in orders:
                    orders[n].append(trade)
                else:
                    orders[n] = deque([trade])
        elif n in orders:
            orders[n].append(trade)
        else:
            orders[n] = deque([trade])

        return match


