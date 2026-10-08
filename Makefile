CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -fcommon

DIRS = graphs/bfs_dfs graphs/adjacency_list graphs/dijkstra_prim backtracking/n_queens data_structures/queue

all:
	@for dir in $(DIRS); do \
		if [ -d "$$dir" ]; then \
			echo "[+] Building $$dir..."; \
			$(CC) $(CFLAGS) $$dir/*.c -o $$dir/runner 2>/dev/null || echo "[-] Skipped $$dir (build error or missing files)"; \
		fi \
	done

clean:
	@find . -type f -name "runner" -delete
	@find . -type f -name "*.o" -delete
	@echo "[*] Cleaned all compiled binaries and object files."
