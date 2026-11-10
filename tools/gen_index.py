#!/usr/bin/env python3
"""Genera el README.md de una carpeta de dificultad de CDFC a partir del
bloque "Tópicos utilizados" en el header de cada .cpp."""
import re
import sys
from pathlib import Path

TOPIC_LINE_RE = re.compile(r'^\|\s*-\s*(.+?)\s*$')
EXCLUDED_TOPICS = {"training"}
DIFFICULTY_TAG_RE = re.compile(r'^\*\d+$')
NO_TOPIC_LABEL = "sin tópico registrado"


def extract_topics(cpp_path: Path) -> list[str]:
    lines = cpp_path.read_text(encoding="utf-8").splitlines()

    start = None
    for i, line in enumerate(lines[:30]):
        if "Tópicos utilizados" in line:
            start = i + 1
            break
    if start is None:
        return []

    topics = []
    for line in lines[start:]:
        m = TOPIC_LINE_RE.match(line)
        if not m:
            break
        topics.append(m.group(1).strip())
    return topics


def meaningful_topics(topics: list[str]) -> list[str]:
    return [t for t in topics if t not in EXCLUDED_TOPICS and not DIFFICULTY_TAG_RE.match(t)]


def build_markdown(folder: Path) -> str:
    cpp_files = sorted(folder.glob("*.cpp"))

    by_topic: dict[str, list[str]] = {}
    rows: list[tuple[str, list[str]]] = []
    for cpp in cpp_files:
        name = cpp.stem
        topics = meaningful_topics(extract_topics(cpp))
        rows.append((name, topics))
        bucket = topics if topics else [NO_TOPIC_LABEL]
        for topic in bucket:
            by_topic.setdefault(topic, []).append(name)

    lines = [f"# Dificultad *{folder.name}", "", "## Detalle por problema", "",
             "| Problema | Tópicos |", "|---|---|"]
    for name, topics in rows:
        topic_str = ", ".join(topics) if topics else "—"
        lines.append(f"| [{name}]({name}.cpp) | {topic_str} |")

    lines += ["", "---", "", "## Índice por tópico", "",
              "| Tópico | Problemas |", "|---|---|"]
    for topic in sorted(by_topic, key=str.lower):
        names = sorted(by_topic[topic], key=str.lower)
        problem_links = ", ".join(f"[{name}]({name}.cpp)" for name in names)
        lines.append(f"| {topic} | {problem_links} |")

    return "\n".join(lines) + "\n"


def main():
    if len(sys.argv) != 2:
        print("Uso: gen_index.py <carpeta>", file=sys.stderr)
        sys.exit(1)

    folder = Path(sys.argv[1])
    if not folder.is_dir():
        print(f"No existe la carpeta: {folder}", file=sys.stderr)
        sys.exit(1)

    markdown = build_markdown(folder)
    (folder / "README.md").write_text(markdown, encoding="utf-8")
    print(f"Generado {folder / 'README.md'}")


if __name__ == "__main__":
    main()
