class Goteras():
    def __init__(self, input):
        self.n_test_cases, self.test_cases = self._parse_input(input)

    def _parse_input(self, input):
        lines = None
        with open(input) as f:
            lines = f.read().splitlines()

        return lines[0], lines[1:]
    
    def _sec_to_hh_mm_ss(self, tot_seconds):
        secs = tot_seconds % 60
        mins = (tot_seconds - secs) % 3600  # minutes in seconds
        hours = tot_seconds - secs - mins   # hours in seconds

        return f"{int(hours/3600):02}:{int(mins/60):02}:{int(secs):02}"

    def _calc_max_time(self, cases):
        results = []
        for case in cases:
            results.append(self._sec_to_hh_mm_ss(int(case)))
        
        return results
    
    def _denouement(self, results):
        output = ""
        for case_solution in results:
            output += case_solution + "\n"
        return output 

    def solve(self):
        results = self._calc_max_time(self.test_cases)
        print(self._denouement(results))

if __name__ == "__main__":
    goteras = Goteras("input")
    goteras.solve()