# 🌙 Lua 5.1.5 — Educational Fork

This repository is a readable fork of Lua `v5.1.5` aimed at learning and exploration. It preserves original behavior while making the codebase easier to follow for studying language internals.

## Goals

- Cleaned comments and small readability-driven refactors (no behavioral changes).
- Focused on teaching: easier to trace VM loop, API and garbage collector.
- Useful for building a minimal Lua for embedded or learning environments.

## Quickstart

### Build

```bash
# build the lua executable
make -j $(nproc)
```

### Test

```bash
make -C tests
```

## License

MIT.
